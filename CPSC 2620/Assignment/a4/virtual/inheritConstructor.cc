class f
{
   public:
      f() : person("Arie") {}
      void write_stuff() {cout << person << endl;}
   private:
      string person;
};

class g : public f
{
   public:
      //If there is no derived class constructor the constructor of the base
      //class is automatically called.
      void setNum(int i) {num=i;}
      int getNum() const {return num;}
      void write_stuff() {f::write_stuff();cout << num << endl;}
   private:
      int num;
};
