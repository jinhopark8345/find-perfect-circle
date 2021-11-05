
#include <exception>
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>    // std::next_permutation, std::sort


using namespace std;

inline bool validate( int n1, int n2, const set<int>& powers )
{
    return ( bool )( powers.count( n1 + n2 ) != 0 );
}

bool validate( const vector<int>& vec, const set<int>& powers )
{

    for ( int i = 0; i < vec.size() - 1; i++ )
    {
        if ( validate( vec[i], vec[i + 1], powers ) == false )
        {
            return false;
        }
    }
    if ( validate( vec[vec.size() - 1], vec[0], powers ) == false )
    {
        return false;
    }

    return true;
}

void print_vec( const vector<int> &cand )
{
    for ( auto n : cand )
        cout << n << " ";
    cout << endl;
    return;
}

void swap( int& a, int& b )
{
    int tmp = a;
    a = b;
    b = tmp;
}

// 순열
void permutate( int cur_idx, int max_len, vector<int> &cand,
                const set<int>& powers, bool& found  )
{

    if ( cur_idx == max_len )
    {
        if ( validate( cand, powers ) )
        {
            print_vec( cand );
            found = true;
        }

        return;
    }

    for ( int i = cur_idx; i < max_len; i++ )
    {
        if ( !found )
        {
            if ( i >= 1 && validate( cand[cur_idx - 1], cand[i], powers ) )
            {
                // print_vec(cand);
                swap( cand[cur_idx], cand[i] );
                // print_vec(cand);
                permutate( cur_idx + 1, max_len, cand, powers, found );
                swap( cand[cur_idx], cand[i] );
            }
            else
                continue;

        }
        else{
            break;
        }
    }
}

set<int> make_m_powers( int len )
{
    int sum = 2 * len - 1;
    int max_num = int( sqrt( sum ) );
    set<int> powers;

    for ( int i = 1; i <= max_num; i ++ )
    {
        powers.insert( pow( i, 2 ) );
    }

    return powers;
}


void print_powers( set<int> ps )
{
    for ( auto p : ps )
        cout << p << " ";
    cout << endl;
}

void make_perfect_circle( size_t len )
{

    // size_t len = 32;
    vector<int> vec( len, ( int )0 );

    for ( int i = 0; i < vec.size(); i++ )
    {
        vec[i] = i + 1;
    }
    auto powers =  make_m_powers( len );
    // print_powers( powers );


    // print_powers( pn.get_powers() );
    // do
    // {
    //     // print_vec(vec);
    //     if ( validate( vec, powers ) )
    //     {
    //         cout << "\tthis is pretty" << endl;
    //         print_vec( vec );
    //     }
    // }
    // while ( std::next_permutation( vec.begin(), vec.end() ) );

    // need to improve by adding/proceeding permutation only when previous elements were correct order

    // vector<int> cand = {1, 2, 3, 4, 5};
    vector<int> cand ( len, 0 );

    for ( int i = 1; i <= len; i++ )
    {
        cand[i - 1] = i;
    }
    // print_vec( cand );
    // cout << endl;

    bool  found = false;
    permutate( 0, len, cand, powers, found );
}
int main()
{
    for ( int i = 1; i < 55; i++ )
    {

        cout << "\ncircle len: " << i << endl;
        make_perfect_circle( i);
    }


    return 0;
}
