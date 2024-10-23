using System;
using System.Diagnostics;

namespace ConsoleAppCompareCppToCSharpSpeed
{
  internal class Program
  {
    static void Main()
    {
      Console.WriteLine("comparaison de vitesse entre une application console écrite en CPP et C#");
      Console.WriteLine("");
      var chrono = new Stopwatch();
      chrono.Start();
      var upperLimit = 1_000_000;
      for (int i = 0; i < upperLimit; i++)
      {
        if (IsPrime(i))
        {
          Console.WriteLine($"{i} is prime");
        }
      }

      chrono.Stop();
      Console.WriteLine($"Le temps écoulé pour calculer les nombres premiers entre 0 et {upperLimit} est : {chrono.Elapsed}");
      Console.WriteLine("Press any key to exit");
      Console.ReadKey();
    }

    public static bool IsPrime(int number)
    {
      if (number <= 1)
      {
        return false;
      }

      if (number == 2 || number == 3 || number == 5)
      {
        return true;
      }

      if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0)
      {
        return false;
      }

      for (int divisor = 7; divisor <= Math.Sqrt(number); divisor += 2)
      {
        if (number % divisor == 0)
        {
          return false;
        }
      }

      return true;
    }
  }
}
