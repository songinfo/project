/*************************************************************************
	> File Name: edistance.cpp
	> Author: Chao
	> Mail:1311159643@qq.com 
	> Created Time: Wed 01 Apr 2015 03:18:09 PM CST
 ************************************************************************/

#include<iostream>
#include<string>

int calcEdistance(const char* pstr1, int len1, const char* pstr2, int len2)
{
int dp[len1+1][len2+1];
  for(int i = 0; i <= len1; ++i)
  {
  dp[i][0] = i;
  }
  for(int j = 0; j <= len2; ++j)
  {
  dp[0][j] = j;
  }
  for(int i = 1; i <= len1; ++i)
  {
     for(int j = 1; j <= len2; ++j )
	 {
	    if(pstr1[i-1] == pstr2[j-1])
	     {
		 dp[i][j] = dp[i-1][j-1];
		 }
		else
		{
		int t1 = dp[i-1][j];
		t1 = t1 < dp[i][j-1] ? t1 :dp[i][j-1];
		t1 = t1 < dp[i-1][j-1] ? t1 :dp[i-1][j-1];
		dp[i][j] = t1 + 1;
		}
	 }
  
  }
  return dp[len1][len2];
}

int main(void)
{
	std::string s1 = "iphxnx";
	std::string s2 = "iphone";
	int len1 = s1.size();
	int len2 = s2.size();
	const char* ps1 = s1.c_str();
	const char* ps2 = s2.c_str();

	int ret = calcEdistance(ps1, len1, ps2, len2);
	std::cout << "The edit distance = " << ret << std::endl;

return 0;
}

