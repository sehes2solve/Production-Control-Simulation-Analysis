#include <iostream>

using namespace std;

const int cost = 450;
pair < long double , long double > average;

int main()
{
    for ( int Pc_demand = 1; Pc_demand <= 2; Pc_demand++ )
    {
        int available_pc = 0 , weekDemand = 0 , totalProfit = 0;
        for ( int weeks = 1; weeks <= 500; weeks++ )
        {
            available_pc += Pc_demand;
            weekDemand    = rand()%5;

            if      ( weekDemand == available_pc )
            {
                totalProfit    += ( available_pc * cost );
                available_pc    = 0;
            }
            else if ( weekDemand <  available_pc )
            {
                totalProfit    += ( weekDemand * cost );
                available_pc   -= weekDemand;
                totalProfit    -= available_pc * 50;
            }
            else if ( weekDemand >  available_pc )
            {
                totalProfit    += ( available_pc * cost );
                weekDemand     -= available_pc;
                totalProfit    -= weekDemand * 100;
                available_pc    = 0;
            }
        }

        cout << "PC weekly demand   : " << Pc_demand    << "\n";
        cout << "Total Profit       : " << totalProfit  << "\n";
        cout << "Average Profit     : " << (1.0*totalProfit)/500 << "\n";
        cout << "\n";

        if      ( Pc_demand == 1 ) average.first  = (1.0*totalProfit)/500;
        else if ( Pc_demand == 2 ) average.second = (1.0*totalProfit)/500;
    }

    cout << "The Best Decision is to order "
         << ( average.first > average.second ? "1 " : "2 " )
         << "unit per week\n";
    return 0;
}
