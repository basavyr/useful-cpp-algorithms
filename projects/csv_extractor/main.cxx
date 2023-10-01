#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>
const char DATA_DIR[]="./data/";

char* c_get_csv_data(const char (&csv_file)[]){
    char full_path[strlen(DATA_DIR)+strlen(csv_file)+2];
    std::strcpy(full_path,DATA_DIR);
    std::strcat(full_path,csv_file);
    std::cout<<"Extracting the csv data from: "<<full_path<<std::endl;
    
    //read data from the file
    std::ifstream file;    
    file.open(full_path);
   
    file.seekg(0, std::ios::beg);
    std::streampos file_start=file.tellg();

    file.seekg(0, std::ios::end);
    std::streampos file_end=file.tellg();
      
    int file_size=int(file_end-file_start);

    //reset cursor position
    file.seekg(0, std::ios::beg);

    char* data=new char[file_size];
    
    //std::cout<<sizeof(data)<<"\n";
 
    char line;
    int index=0;
    if (file.is_open()) {
        while (file) {
            line=file.get();
            data[index]=line;
            //std::cout<<data[index];
            index++;
            //std::getline(file,line);        
            //std::cout<<line<<"\n";
        }
    }
    return data;
}


std::vector<std::string> get_csv_data(const std::string &csv_file) {
    std::vector<std::string> csv_data;
    
    std::ifstream file;
    std::string csv_file_path=DATA_DIR+csv_file;
    
    file.open(csv_file_path);
    
    std::string line;
    if(file.is_open())
    {
        while (getline(file,line))
        {
            csv_data.emplace_back(std::move(line));
        }
    }
 
    return csv_data;
}

struct pair {
    double x;
    double y;
};

struct PhotoAbs {
    std::vector<double> omega; //energy
    std::vector<double> sigma; //cross-section for Photo-Absorbtion
    pair xy;
};


PhotoAbs extract_data(std::vector<std::string> &csv_data)
{
    PhotoAbs results;
    return results;
}


class Printer {
   public:
        template<typename T>
        void print(T &variable)
        {
	    std::cout<<"lvalue ref constructor\n";
            std::cout<<variable<<"\n";
        }
       
        template<typename T>
        void print(T &&variable)
        {
	    std::cout<<"rvalue ref constructor\n";
            std::cout<<variable<<"\n";
        }  
	template<typename V_type>
	void print(std::vector<V_type> &v)
	{
            for(auto &&n : v)
	    {
		std::cout<<n<<" ";
	    }
	    std::cout<<std::endl;
	}
    private:
        const double backup=1.1;
	// template<typename T>
        // void print(T &variable)
        // {
	//     std::cout<<"lvalue ref constructor\n";
	// }
	// template<typename T>
        // void print(T &&variable)
        // {
	//     std::cout<<"rvalue ref constructor\n";
	// }
};


void csv_workflow_c()
{
    const char csv_file[]="Gd160-sn_MAGENTA.csv";
    char *csv_data=c_get_csv_data(csv_file);
    for(auto index=0;index<=10;index++){
        std::cout<<csv_data[index];
    }
    delete[] csv_data;
}


int main()
{
    const std::string csv_file="Gd160-sn_MAGENTA.csv";
    Printer print;
    auto csv_data=get_csv_data(csv_file);

    PhotoAbs parsed_data;  

    for(size_t index=1;index<csv_data.size();++index)
    {
        //const std::size_t current_split=current_string.find(",");
        parsed_data.xy.x=std::stod(csv_data.at(index).substr(0,csv_data.at(index).find(",")));
        parsed_data.xy.y=std::stod(csv_data.at(index).substr(csv_data.at(index).find(",")+1,csv_data.at(index).length()-1));
        try{
            parsed_data.omega.emplace_back(std::move(parsed_data.xy.x));
	    parsed_data.sigma.emplace_back(std::move(parsed_data.xy.y));
        }
        catch (std::invalid_argument const &ex)
	{
	    std::cout<<"issue -> "<<ex.what()<< "\n";
	}
    }
    print.print(parsed_data.omega);
    print.print(parsed_data.sigma);
    print.print(5);  
//    for(auto &&line: csv_data)
//    {
//        print.print(line);
//    }

    return 0;
}

