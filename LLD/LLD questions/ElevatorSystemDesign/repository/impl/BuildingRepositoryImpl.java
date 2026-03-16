package repository.impl;

import domain.Building;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;
import repository.BuildingRepository;

public class BuildingRepositoryImpl implements BuildingRepository {
    private Map<String, Building> buildings = new ConcurrentHashMap<>();

    @Override
    public Building save(Building building) {
        buildings.put(building.getId(), building);
        return building;
    }

    @Override
    public Optional<Building> findById(String buildingId) {
        return Optional.ofNullable(buildings.get(buildingId));
    }

    @Override
    public List<Building> findAll() {
        return new ArrayList<>(buildings.values());
    }

    @Override
    public void deleteById(String buildingId) {
        buildings.remove(buildingId);
    }
}
