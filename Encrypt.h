class Cube 
{
public:    
    Cube() = default;    
    Cube (const std::string & , const std::string &);    
public:
    void Start();
private:
    void Decrypt();
    void Print();     
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    void Code();
    void Decode();
    std::string _Text ;
    std::string _Key ;
    std::string _MyKey { "L:!" } ;
    std::string _MyKey1 { "R!" } ;
    static const int CubeLength { 8 } ;
} ;
