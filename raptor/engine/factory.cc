//
// Created by liyinbin on 2020/4/17.
//

#include <abel/thread/mutex.h>
#include <raptor/engine/factory.h>
#include <abel/asl/flat_hash_map.h>
#include <abel/thread/mutex.h>
#include <abel/log/abel_logging.h>
#include <raptor/engine/engine.h>

namespace raptor {

    struct engine_info {
        int index;
        engine_creator creator;

    };
    static abel::mutex global_register_guard{};

    static abel::flat_hash_map<abel::string_view, engine_info> global_register{};

    int engine_register(int engine_index, abel::string_view engine_name, engine_creator ec) {
        abel::mutex_lock lk(&global_register_guard);
        ABEL_ASSERT_MSG(ec != nullptr, "engine creator is nullptr");
        auto itr = global_register.find(engine_name);
        if (itr != global_register.end()) {
            engine_info ei;
            ei.index = engine_index;
            ei.creator = ec;
            global_register[engine_name] = ei;
            return 0;
        }
        ABEL_RAW_CRITICAL("creator has been registered {}", itr->first);
        return -1;
    }

    std::vector<abel::string_view> list_engine() {
        abel::mutex_lock lk(&global_register_guard);
        std::vector<abel::string_view> ret;
        for (auto itr = global_register.begin(); itr != global_register.end(); ++itr) {
            ret.push_back(itr->first);
        }
        return ret;
    }

    engine *create(abel::string_view engine_name) {
        abel::mutex_lock lk(&global_register_guard);
        auto itr = global_register.find(engine_name);
        if (itr == global_register.end()) {
            return nullptr;
        }
        return itr->second.creator();
    }

} //namespace raptor