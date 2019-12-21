using System;
using System.Collections.Generic;
using System.Text;

namespace ChickensCSharp
{
    class Organism
    {
        //Static counter for all organism Ids
        private static int currentOrganismId;
        public int Id { get; set; }
        public string Name { get; set; }
        // Default Constructor
        public Organism()
        {
            this.Id = 0; // Incomplete organisms are created with an Id of 0.  Use this Id to sanitise methods
            this.Name = "";
        }
        public Organism(string name)
        {
            this.Id = GetNextID();
            this.Name = name;
        }
        protected int GetNextID()
        {
            return ++currentOrganismId;
        }
    }
}
