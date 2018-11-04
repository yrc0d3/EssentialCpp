#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline float max(float a, float b)
{
    return a > b ? a : b;
}

inline string max(const string &a, const string &b)
{
    return a > b ? a : b;
}

inline int max(const vector<int> &vec)
{
    return *max_element(vec.begin(), vec.end());
}

inline float max(const vector<float> &vec)
{
    return *max_element(vec.begin(), vec.end());
}

inline string max(const vector<string> &vec)
{
    return *max_element(vec.begin(), vec.end());
}

inline int max(const int *arr, int size)
{
    return *max_element(arr, arr + size);
}

inline float max(const float *arr, int size)
{
    return *max_element(arr, arr + size);
}

inline string max(const string *arr, int size)
{
    return *max_element(arr, arr + size);
}

int main()
{
	string sarray[]={ "we", "were", "her", "pride", "of", "ten" };
    vector<string> svec( sarray, sarray+6 );

    int iarray[]={ 12, 70, 2, 169, 1, 5, 29 };
    vector<int> ivec( iarray, iarray+7 );

    float farray[]={ 2.5, 24.8, 18.7, 4.1, 23.9 };
    vector<float> fvec( farray, farray+5 );

    int imax = max( max( ivec ), max( iarray, 7 ));
    float fmax = max( max( fvec ), max( farray, 5 ));
    string smax = max( max( svec ), max( sarray, 6 ));

	cout << "imax should be 169  -- found: " << imax << "\n"
		 << "fmax should be 24.8 -- found: " << fmax << "\n"
		 << "smax should be were -- found: " << smax << "\n";

    return 0;
}
