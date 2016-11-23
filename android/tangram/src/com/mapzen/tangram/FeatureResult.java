package com.mapzen.tangram;

import java.util.Map;

public class FeatureResult {

    FeatureResult(Map<String, String> properties) {
        this.properties = properties;
    }

    public Map<String, String> getProperties() {
        return properties;
    }

    private Map<String, String> properties;
}
