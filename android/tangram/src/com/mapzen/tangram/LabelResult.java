package com.mapzen.tangram;

import java.util.Map;

public class LabelResult extends FeatureResult {

    public enum Type {
        ICON,
        TEXT,
    }

    LabelResult(Map<String, String> properties, double lng, double lat, int type) {
        super(properties);
        this.coordinates = new LngLat(lng, lat);
        this.type = Type.values()[type];
    }

    public LngLat getCoordinates() {
        return coordinates;
    }

    public Type getType() {
        return type;
    }

    private LngLat coordinates;
    private Type type;
}
