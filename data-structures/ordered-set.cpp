#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// st.find_by_order(k) -> Retorna un iterador al k-ésimo elemento 
// st.order_of_key(x) -> Retorna el número de elementos estrictamente menores a x
// para eliminar:
// int idx = st.order_of_key(value);
// st.erase(st.find_by_order(idx));