#include <iostream>
#include <cmath>
#include <chrono>

bool IsPrime(int number)
{
  if (number <= 1)
    return false;

  if (number == 2 || number == 3 || number == 5)
    return true;

  if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0)
    return false;

  for (int divisor = 7; divisor <= std::sqrt(number); divisor += 2)
  {
    if (number % divisor == 0)
      return false;
  }

  return true;
}

int main()
{
  std::cout << "Comparaison de vitesse entre une application console ecrite en CPP et C#" << std::endl;
  std::cout << std::endl;

  auto chrono = std::chrono::high_resolution_clock::now();
  int upperLimit = 1'000'000;

  for (int i = 0; i < upperLimit; ++i)
  {
    if (IsPrime(i))
    {
      std::cout << i << " is prime" << std::endl;
    }
  }

  auto chronoEnd = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(chronoEnd - chrono).count();

  std::cout << "Le temps ecoule pour calculer les nombres premiers entre 0 et " << upperLimit << " est : " << duration << " ms" << std::endl;
  std::cout << "Press any key to exit" << std::endl;

  std::cin.get(); // Pause avant de quitter
  return 0;
}
