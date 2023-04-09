s = '''const int N = 1e6 + 10;
int fac[N];
 
int modpow(int a, int b, int mod) {
   int res = 1;
   a %= mod;
   while (b > 0){
       if(b & 1)
           res = (res * a) % mod;
       a = (a * a) % mod;
       b >>= 1;
   }
   return res;
}
 
void pre() {
   fac[0] = 1;
   for (int i = 1; i < N; i++)
       fac[i] = fac[i - 1] * i % MOD;
}
 
int ncr(int n, int r) {
   int num = fac[n];
   int den = modpow(fac[n - r] * fac[r] % MOD, MOD - 2, MOD);
   return num * den % MOD;
}
'''
ans = "\""
# for x in s:
	# if(x == '\n'):
		# ans += "\\n"
	# elif(x == '\t'):
		# ans += "\\t"
	# else:
		# ans += x
i = 0
while i < len(s):
  if s[i] == ' ' and s[i + 1] == ' ':
    ans += '\\t'
    i += 1
  elif s[i] == '\n':
    ans += "\",\n\""
  elif(s[i] == '\t'):
    ans += "\\t"
  else:
    ans += s[i]
  i += 1

ans += "\""
		
print(ans)
