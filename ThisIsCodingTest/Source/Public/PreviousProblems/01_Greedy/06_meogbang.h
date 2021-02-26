#include <iostream>
#include <queue>
#include <utility>
#include <vector>

namespace meogbang
{
	class Greater
	{
	public:
		bool operator()( const std::pair<int, int>& lhs, const std::pair<int, int>& rhs )
		{
			return lhs.first > rhs.first;
		}
	};

	int solve( std::vector<int> food_times, long long k )
	{
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Greater> q( Greater{} );

		for ( std::size_t i = 0; i < food_times.size( ); ++i )
		{
			q.push( { food_times[i], i } );
		}

		int previousTime = 0;
		while ( q.empty( ) == false )
		{
			auto time = q.top( );
			long long totalTime = ( time.first - previousTime ) * q.size( );

			if ( k >= totalTime )
			{
				k -= totalTime;
				previousTime = time.first;
				q.pop( );
			}
			else
			{
				break;
			}
		}

		if ( q.empty( ) )
		{
			return -1;
		}

		std::vector<int> remains;
		while ( q.empty( ) == false )
		{
			remains.push_back( q.top( ).second );
			q.pop( );
		}

		std::sort( std::begin( remains ), std::end( remains ) );

		return remains[k % remains.size( )] + 1;
	}
}