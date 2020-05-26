#include "utils.h"
#include <random>

std::unique_ptr<std::vector<bool>> generate_random_vector(const double p_success, const size_t simulation_size) {
  std::vector<bool> res;
  res.reserve(simulation_size);
  std::default_random_engine generator;
  std::bernoulli_distribution bernoulli(p_success);
  for (size_t i = 0; i < simulation_size; i++) {
    res.push_back(bernoulli(generator));
  }
  return std::make_unique<std::vector<bool>>(std::vector<bool>(res));
}