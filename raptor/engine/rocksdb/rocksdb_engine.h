//
// Created by liyinbin on 2020/4/24.
//

#ifndef RAPTOR_ROCKSDB_ENGINE_H_
#define RAPTOR_ROCKSDB_ENGINE_H_

#include <raptor/engine/engine.h>

namespace raptor {

    class rocksdb_engine;

    class rocksdb_iterator : public engine_iterator {
    public:
        rocksdb_iterator(rocksdb_engine *engine, rocksdb::ColumnFamilyHandle *cf, abel::string_view ns)

        bool valid();

        void next() ;

        void prev();

        void jump() ;

        void jump_head() ;

        void jump_tail() ;

        abel::string_view key();

        abel::string_view value() ;

        /*
         * Delete key/value pair at current iterator position.
         * It's more efficient, and the only right way to delete data in iterator for some engine(forestdb).
         */
        void remove();

        
    private:
        std::string _namespace;

    };

    class rocksdb_engine : public engine {
    public:
        int init(abel::any config);

        int put(const key_type &key, abel::string_view value);

        int get(const key_type &key, std::string &value);

        int remove(const key_type &key) = 0;

        int remove_keys(abel::string_view column_name);

        int remove_all_keys() = 0;

        int remove_range(const key_type &start, const key_type &end);

        int multi_get(const std::vector<key_type> &keys, std::vector<std::string> &values);

        int
        multi_set(const std::vector<key_type> &keys, const std::vector<std::string> &values);

        int exists(const key_type &keys, bool &result);

        engine_iterator *find(const key_type &key);

        int compact(const key_type &start, const key_type &end);

        int compact_all();

        int create_column(abel::string_view column_name);

        int list_column(std::vector<std::string> &result);

        int remove_column(abel::string_view column_name);

        int flush(abel::string_view column_name);

        int flush_all();

        int backup(const abel::filesystem::path &dir);

        int restore(const abel::filesystem::path &dir);

        int estimate_keys(abel::string_view column_name);

        int estimate_keys_all();

        int repair();

        int start_write_batch();

        int commit_write_batch();

        int discard_write_batch();

        const feature_set get_feature();

        engine_snapshot create_snapshot() {
            return nullptr;
        }

        int release_snapshot(engine_snapshot s) {
            return 0;
        }

        int max_open_files();

        ~engine() {

        }

    private:
        rocksdb::DB *_db;
        rocksdb::Options _options;
        std::string _db_dir;
    };

}
#endif //RAPTOR_ROCKSDB_ENGINE_H_
