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
        public bool IsFemale { get; set; }
        //Default constructor
        public Animal()
        {
            this.IsAnimal = true;
        }
        public Animal(string name, Animal mother, Animal father, bool isFemale):base(name)
        {
            this.IsAnimal = true;
            this.Mother = mother;
            this.Father = father;
            this.IsFemale = IsFemale;
        }
    }
}
