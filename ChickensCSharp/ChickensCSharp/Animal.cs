using System;
using System.Collections.Generic;
using System.Text;

namespace ChickensCSharp
{
    class Animal : Organism
    {
        public bool IsAnimal { get; set; }
        public Animal Mother { get; set; }
        public Animal Father { get; set; }
    }
}
