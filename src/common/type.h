#include <cstddef>
#include <cstdint>
#include "unistd.h"
#include <memory>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <any>

using byte = uint8_t;
using u8   = uint8_t;
using u16  = uint16_t;
using u32  = uint32_t;
using u64  = uint64_t;
using i8   = int8_t;
using i16  = int16_t;
using i32  = int32_t;
using i64  = int64_t;
using u1   = u8;
using u2   = u16;
using u4   = u32;
using float32 = float;
using float64 = double;

using Buffer = std::vector<byte>;
using U16Buffer = std::vector<u16>;
using shared_buffer = std::shared_ptr<Buffer>;
using shared_u16Buffer = std::shared_ptr<U16Buffer>;
template<typename T>
using shared = std::shared_ptr<T>;

using string = std::string;
template<typename T>
using vector = std::vector<T>;

template<typename K, typename V>
using umap = std::unordered_map<K, V>;

template<typename T>
using vs = vector<shared<T>>;

template<typename T>
using sv = shared<vector<T>>;

template<typename T>
using svs = shared<vector<shared<T>>>;

template<typename... Args>
using tuple = std::tuple<Args...>;

using std::make_shared;
using std::make_unique;
using std::any;
using std::any_cast;

