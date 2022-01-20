//
// Created by romchirik on 21.01.2022.
//

#ifndef SHIPSFIGHT_SHIPS_FACTORY_H
#define SHIPSFIGHT_SHIPS_FACTORY_H

//
// Created by romchirik on 20.01.2022.
//

#ifndef SHIPSFIGHT_PLAYER_FACTORY_H
#define SHIPSFIGHT_PLAYER_FACTORY_H


#include <string>
#include <memory>
#include <unordered_map>
#include <functional>
#include "Ship.h"
#include "Ship_type.h"

class Ships_factory {
public:
    std::unique_ptr<Ship> create(Ship_type type);

    static Ships_factory &getInstance() {
        static Ships_factory instance;
        return instance;
    }

    Ships_factory(Ships_factory const &) = delete;
    void operator=(Ships_factory const &) = delete;

private:
    Ships_factory();
    std::unordered_map<Ship_type, std::function<std::unique_ptr<Ship>()>> creators;
};


#endif //SHIPSFIGHT_PLAYER_FACTORY_H


#endif //SHIPSFIGHT_SHIPS_FACTORY_H
