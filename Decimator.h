#include <vector>

class Decimator {
public:
    std::vector<int> duglas_peker(const std::vector<std::pair<int, double>> &values, double e);
    std::vector<std::pair<int, double>> line_bucket(const std::vector<std::pair<int, double>> &values, unsigned bucket_count);
    std::vector<std::pair<int, double>> triangle_bucket(const std::vector<std::pair<int, double>> &values, unsigned bucket_count);
};