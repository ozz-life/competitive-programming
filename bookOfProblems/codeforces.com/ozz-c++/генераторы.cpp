// Сгенерировать последовательности от N с конца до 1

std::generate_n(std::back_inserter(answer), n, [n]() mutable
                { return n--; });

std::generate(answer.begin(), answer.end(), [i = n]() mutable
              { return i--; });

std::generate(answer.begin(), answer.end(), [n]() mutable
              { return n--; });

// Сумма всех элементов в массиве

return std::accumulate(a.begin(), a.end(), 0) + std::accumulate(b.begin(), b.end(), 0);

return std::accumulate(std::begin(a), std::end(a), 0) + std::accumulate(std::begin(b), std::end(b), 0);

int sumOf(std::vector<int> a)
{
    return std::accumulate(a.begin(), a.end(), 0);
}

int sumOf(std::vector<int> a)
{
    return std::accumulate(std::begin(a), std::end(a), 0);
}


// Сравнение даблов 

bool approx_equals(double a, double b) {
  return abs(a - b) < 0.001;
}

