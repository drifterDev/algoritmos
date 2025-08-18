// O(n*log(log(n)))
vector<ll> primes;
vector<bool> is_prime;
void sieve(ll n){
	is_prime.assign(n+1,true);
	for(ll i=2;i<=n;++i){
		if(!is_prime[i])continue;
		for(ll j=i*i;j<=n;j+=i)is_prime[j]=false;
		primes.push_back(i);
	}
}

// criba lineal
vector<int> f;
vector<int> primes;
vector<bool> is_composite;
void sieve(int n){
	f.assign(n+1,1);
	is_composite.assign(n+1,false);
	// caso base en 1, phi[1]=1;
	for(int i=2;i<n;++i){
		if(!is_composite[i]){ // i es primo
			primes.push_back(i);
			// caso para primos, phi[i]=i-1;
		}
		for(int j=0;j<sz(primes) && 1ll*i*primes[j]<1ll*n;++j){
			is_composite[i*primes[j]]=true;
			if(i%primes[j]==0){
				// caso primes[j] divide a i, phi[i * primes[j]] = phi[i] * primes[j];	
				break;
			}else{
				// caso primes[j] no divide a i, phi[i * primes[j]] = phi[i] * phi[primes[j]];
			}
		}
	}
}

// O((R-L+1)log(log(R))+sqrt(R)log(log(sqrt(R)))
// R-L+1 <= 1e7, R <= 1e14
void segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R)+3;
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
}