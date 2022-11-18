#include "Decimator.h"

#include <stack>
#include <cmath>

std::vector<int> Decimator::duglas_peker(const std::vector<std::pair<int, double>> &values, double e)
{
    std::vector<int> values_for_return;
    unsigned i = 0;
    int startIndex = 0;
    int endIndex = 0;
    double dMax = 0;
    int index = 0;
    double d = 0, p = 0;
    double length_of_line = 0, length_of_line1 = 0, length_of_line2 = 0;
    double a_hight = 0, b_hight = 0;

    std::stack<std::pair<int, int>> index_of_value;
    index_of_value.push({0, values.size() - 1});

    while(!index_of_value.empty())
    {
        startIndex = index_of_value.top().first;
        endIndex = index_of_value.top().second;

        index_of_value.pop();

        dMax = 0;

        a_hight = values[endIndex].first - values[startIndex].first;
        b_hight = values[endIndex].second - values[startIndex].second;
        length_of_line = std::sqrt(a_hight * a_hight + b_hight * b_hight);

        for(i = startIndex + 1; i < endIndex; ++i)
        {
            d = std::abs(b_hight * values[i].first - a_hight * values[i].second + values[endIndex].first * values[startIndex].second - values[endIndex].second * values[startIndex].first) / length_of_line;

            if(d > dMax)
            {
                index = i;
                dMax = d;
            }
        }

        if(dMax >= e)
        {
            index_of_value.push({index, endIndex});
            index_of_value.push({startIndex, index});
        }
        else
            values_for_return.push_back(startIndex);
    }

    values_for_return.push_back(values.size() - 1);

    return values_for_return;
}

std::vector<std::pair<int, double>> Decimator::line_bucket(const std::vector<std::pair<int, double>> &values, unsigned bucket_count)
{

}

std::vector<std::pair<int, double>> Decimator::triangle_bucket(const std::vector<std::pair<int, double>> &values, unsigned bucket_count)
{

}