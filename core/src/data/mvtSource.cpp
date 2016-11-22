#include "mvtSource.h"

#include "tileData.h"
#include "tile/tileID.h"
#include "tile/tile.h"
#include "tile/tileTask.h"
#include "util/pbfParser.h"
#include "log.h"

namespace Tangram {


MVTSource::MVTSource(const std::string& _name, const std::string& _urlTemplate,
                     int32_t _minDisplayZoom, int32_t _maxDisplayZoom, int32_t _maxZoom) :
    DataSource(_name, _urlTemplate, _minDisplayZoom, _maxDisplayZoom, _maxZoom) {
}

std::shared_ptr<TileData> MVTSource::parse(const TileTask& _task, const MapProjection& _projection) const {

    auto tileData = std::make_shared<TileData>();

    auto& task = static_cast<const DownloadTileTask&>(_task);

    protobuf::message item(task.rawTileData->data(), task.rawTileData->size());
    PbfParser::ParserContext ctx(m_id);

    try {
        while(item.next()) {
            if(item.tag == 3) {
                tileData->layers.push_back(PbfParser::getLayer(ctx, item.getMessage()));
            } else {
                item.skip();
            }
        }
    } catch(const std::invalid_argument& e) {
        LOGE("Cannot parse tile %s: %s", _task.tileId().toString().c_str(), e.what());
        return {};
    } catch(const std::runtime_error& e) {
        LOGE("Cannot parse tile %s: %s", _task.tileId().toString().c_str(), e.what());
        return {};
    } catch(...) {
        return {};
    }
    return tileData;
}

}
