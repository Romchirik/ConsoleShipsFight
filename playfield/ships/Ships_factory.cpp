#include "Ships_factory.h"
#include "Smol_ship.h"
#include "Big_ship.h"
#include "Huge_ship.h"
#include "Incredibly_huge_ship.h"

std::unique_ptr<Ship> Ships_factory::create(Ship_type type) {
    return creators[type]();
}

Ships_factory::Ships_factory() {
    creators.insert(std::make_pair(SMOL, [] { return std::unique_ptr<Smol_ship>(); }));
    creators.insert(std::make_pair(BIG, [] { return std::unique_ptr<Big_ship>(); }));
    creators.insert(std::make_pair(HUGE, [] { return std::unique_ptr<Huge_ship>(); }));
    creators.insert(std::make_pair(INCREDIBLY_HUGE, [] { return std::unique_ptr<Incredibly_huge_ship>(); }));
}
