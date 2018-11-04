#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename Type>
inline Type max(Type a, Type b)
{
    return a > b ? a : b;
}

template <typename elemType>
inline elemType max(const vector<elemType> &a)
{
    return *max_element(a.begin(), a.end());
}

template <typename arrType>
inline arrType max(const arrType *arr, int size)
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
