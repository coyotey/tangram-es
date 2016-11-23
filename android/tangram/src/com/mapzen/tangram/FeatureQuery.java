package com.mapzen.tangram;

import android.support.annotation.Nullable;

import java.util.Map;

public abstract class FeatureQuery {

    public FeatureQuery(float screenX, float screenY) {
        this.x = screenX;
        this.y = screenY;
    }

    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }

    public abstract void onQueryComplete(@Nullable FeatureResult feature, @Nullable LabelResult label);

    private float x;
    private float y;

    static void resultFromNative(FeatureQuery query, Map<String, String> properties, double lng, double lat, int type) {
        if (properties == null) {
            query.onQueryComplete(null, null);
        } else if (type > 0) {
            query.onQueryComplete(null, new LabelResult(properties, lng, lat, type));
        } else {
            query.onQueryComplete(new FeatureResult(properties), null);
        }
    }
}
