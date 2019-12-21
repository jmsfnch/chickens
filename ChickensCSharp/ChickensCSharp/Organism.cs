using System;
using System.Collections.Generic;
using System.Text;

namespace ChickensCSharp
{
    class Organism
    {
        public int Id { get; set; }
        public string Name { get; set; }
        // Default Constructor
        public Organism()
        {
            this.Name = "";
        }
    }
}
