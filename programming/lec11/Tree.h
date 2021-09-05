#ifndef TREE_H
#define TREE_H

class Tree {
    public:

        virtual void Seed() { number_seeds_ += 1; num_trees_+=1;};

        int get_number_seeds() { return number_seeds_; }

        static int num_trees_;

    private:
        static int number_seeds_;
};

class Leaf  :   public Tree {
    public: 
        Leaf()  :   Tree(){}
        void Seed() {number_seeds_ += 2; num_trees_++;}
    private:
        int number_seeds_;
};

#endif // TREE_H
