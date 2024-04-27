#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

gp_hash_table<int, int> table({}, {}, {}, {}, {1 << 13}); // siempre potencia de 2


// auto it = table.find(x);
// if(it != table.end()) ans += it->second;