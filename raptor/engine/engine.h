//
// Created by liyinbin on 2020/4/17.
//

#ifndef RAPTOR_ENGINE_ENGINE_H_
#define RAPTOR_ENGINE_ENGINE_H_

#include <abel/asl/string_view.h>
#include <abel/chrono/clock.h>
#include <abel/asl/filesystem.h>
#include <abel/asl/any.h>

namespace raptor {

    struct engine_iterator {

        engine_iterator();

        virtual bool valid() = 0;

        virtual void next() = 0;

        virtual void prev() = 0;

        virtual void jump() = 0;

        virtual void jump_head() = 0;

        virtual void jump_tail() = 0;

        virtual abel::string_view key() = 0;

        virtual abel::string_view value() = 0;

        /*
         * Delete key/value pair at current iterator position.
         * It's more efficient, and the only right way to delete data in iterator for some engine(forestdb).
         */
        virtual void remove() = 0;

        virtual ~engine_iterator() {}
    };

    struct feature_set {
        unsigned support_namespace :1;
        unsigned support_compactfilter :1;
        unsigned support_merge :1;
        unsigned support_backup :1;
        unsigned support_delete_range :1;

        feature_set() :
                support_namespace(0), support_compactfilter(0), support_merge(0), support_backup(0),
                support_delete_range(
                        0) {
        }
    };

    struct key_type {
        abel::string_view key;
        abel::string_view column;
        abel::abel_time expire;

        key_type() = default;

        ~key_type() = default;
    };

    typedef const void *engine_snapshot;

    class engine {
    public:

        virtual int init(abel::any config) = 0;

        virtual int put(const key_type &key, abel::string_view value) = 0;

        virtual int get(const key_type &key, std::string &value) = 0;

        virtual int remove(const key_type &key) = 0;

        virtual int remove_keys(abel::string_view column_name) = 0;

        virtual int remove_all_keys() = 0;

        virtual int remove_range(const key_type &start, const key_type &end) = 0;

        virtual int multi_get(const std::vector<key_type> &keys, std::vector<std::string> &values) = 0;

        virtual int
        multi_set(const std::vector<key_type> &keys, const std::vector<std::string> &values) = 0;

        virtual int exists(const key_type &keys, bool &result) = 0;

        virtual engine_iterator *find(const key_type &key) = 0;

        virtual int compact(const key_type &start, const key_type &end) = 0;

        virtual int compact_all();

        virtual int create_column(abel::string_view column_name) = 0;

        virtual int list_column(std::vector<std::string> &result) = 0;

        virtual int remove_column(abel::string_view column_name);

        virtual int flush(abel::string_view column_name) = 0;

        virtual int flush_all() = 0;

        virtual int backup(const abel::filesystem::path &dir) = 0;

        virtual int restore(const abel::filesystem::path &dir) = 0;

        virtual int estimate_keys(abel::string_view column_name) = 0;

        virtual int estimate_keys_all() = 0;

        virtual int repair() = 0;

        virtual int start_write_batch() = 0;

        virtual int commit_write_batch() = 0;

        virtual int discard_write_batch() = 0;

        virtual const feature_set get_feature() = 0;

        virtual engine_snapshot create_snapshot() {
            return nullptr;
        }

        virtual int release_snapshot(engine_snapshot s) {
            return 0;
        }

        virtual int max_open_files() = 0;

        virtual ~engine() {

        }

    };

} //namespace raptor

#endif //RAPTOR_ENGINE_ENGINE_H_
