using System;

namespace ChickensCSharp
{
    class Program
    {
        protected static Animal god = new Animal(); // god will have an id of 0.  It will likely be removed later
        Animal adam = new Animal("adam", god, god, false);
        Animal eve = new Animal("eve", god, god, true);

        static void Main(string[] args)
        {

            Console.WriteLine("Hello World!");
        }
    }
}
