/* Return next prime; assume N >= 10 */
int NextPrime(int N)
{
	int i;

	if( N % 2 == 0 )
		N++;
	for( ; ; N += 2 ) {
		for( i = 3; i * i <= N; i += 2 )
			if( N % i == 0 )
				goto ContOuter;  /* Sorry about this! */
		return N;
		ContOuter: ;
	}
}

