//
// Created by liyinbin on 2020/4/17.
//

#ifndef RAPTOR_ENGINE_FACTORY_H_
#define RAPTOR_ENGINE_FACTORY_H_

#include <abel/asl/string_view.h>
#include <raptor/engine/engine.h>
#include <vector>
#include <functional>

namespace raptor {

    typedef std::function<engine*()> engine_creator;

    extern int engine_register(int engine_index, std::string_view engine_name, engine_creator);

    std::vector<abel::string_view> list_engine();

    engine *create(abel::string_view engine_name);

    template<int engine_index>
    struct engine_register_helper {
    };

} //namespace raptor

#define RAPTOR_REGISTER_ENGINE(engine_index, engine_name, creator)                   \
const int ABEL_ALLOW_UNUSED ABEL_CONCAT(engine_dummy_, __LINE__) =              \
    ::abel::engine_register((engine_index), (engine_name),(creator)); \
    template <> class ::abel::engine_register_helper<engine_index> {};

#endif //RAPTOR_ENGINE_FACTORY_H_
