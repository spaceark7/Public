#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <array>



using namespace std;
using vecs = vector<vector<string>>;

// Definisi fungsi ada dibawah
void print_grup (int, const vecs &);

vector<string> anggota = {"Abdul Wahid","Achmad Jumandika","Adam Gabrielle Christian","Aditya Nurohman","Agus Afiat","Ahmad Fauzi","Ahmad Sofyan","Angga Prasetyo","Anto Wijaya","Arif Al Imroni","Ayu Destiana","Bierhoff Siagian","Christian Stevanus","Dedi Susanto","Denny Charles Sagala","Depi Aprilianti","Dhana Bagas","Diky Dermawan","Edi Suprayitno","Eka Fitriyani","Fadhila Ilham","Fadil Mauladi","Faishal Ramadhan","Fikri Muhammad","Firmadi Jeckson Larosa","Habbel Happy Asrin","Heru Hermawan","Heru Laksana","Ibnu Juanda","Intan Nurmala Sari","Irma Handayani","Lailie Maftuha","Leo Hadi Wijaya","M. Ahmad Ismail","Mawadah","Muhamad Miftah","Muhammad Adlan","Muhammad Kamiludin","Muhammad Ridwan","Mukharom Dwi","Muliana Feibe Pangkerego","Ogik Adi Prayitna","Opik Taopik","Renza Devianita","Retno Ayu Amalia","Rezqy Bagastiyadi","Rio Pratama","Rizky Pratama Putra","Royyani Habibah","Rudi Nurdiansyah","Sandy Pramana","Seprian Pratama","Setya Ratna Mulatsih","Shasa Islami","Shinta Eka Pertiwi","Siti Badriah","Sity Meysitoh","Sumarno","Ummul Khaeriah","Wahyu Aminudin"};

// potensi overhead jangan ditiru hanya untuk contoh aja
 static int ctr{1}; 
    
    
 
  
 

int main() {
   // variable untuk jumlah kelompok
    int jumkel{0}; 
    
   // seeding untuk nilai random di fungsi shuffle
    srand (time(0));
    
    // container untuk data anggota. jangan ditiru karena performanya buruk >3 words data yg di assignment
    vector<string> myvec;
    myvec.reserve(60); // tuning 10% perf
    myvec = anggota; // jangan ditiru sungguh!
    
   // Shuffeling data anggota 
    random_shuffle(myvec.begin(), myvec.end());
    
    // lambda capture. fungsi ini untuk memberikan nilai yg berbeda pada saat Shuffeling dilakukan
    random_shuffle(myvec.begin(), myvec.end(), [] (int i) {
       return rand() % i;
    });
    
    
    cout << "Jumlah anggota adalah " << anggota.size() << " orang.\n";
    
    cout << "Masukan jumlah kelompok yg diinginkan (2-10): \n";
    
    cin >> jumkel;
    
    // pre-cond check contoh aja
    if (jumkel == 1 || jumkel < 1 || jumkel > 10) {
    cerr <<"input tidak valid";
    return 0;
    }
    
    // multidimensional vector untuk menyimpan data yg udah di shuffle. juga sbagai output print
    vector<vector<string>> grup(jumkel, vector<string>{});
    
    // iterator untuk mengisi value pada vector diatas
    auto dist = myvec.begin();
    
    //kalkulasi sbg acuan saat looping mengisi data
    int rep = anggota.size() / jumkel;
    int sisa = anggota.size() % jumkel;
    
    // iterasi dan pengisian data e grup
  for (int i = 0; i < rep; i++) {
     for (int j = 0; j < jumkel; j++) {
     grup[j].push_back(*dist);
       dist++;
       }
    }
    
    // kalkulasi tambahan apabila ada sisa
 if (sisa && dist != myvec.end()) {
      for (int j{0}; j < sisa; j++)
    {
       grup[j].push_back(*dist);
       dist++;  
    }   
         
   }

for (int i{0}; i < jumkel; i++)
   print_grup(i, grup);
 
    
    
    return 0;
}


void print_grup(int no, const vecs& kelompok) {
    
    int i = no;
   
           
      cout << "Anggota kelompok " << no+1 << " adalah:\n";
      
      for (const auto& c: kelompok[i]) 
      {              
       cout << "No." << ctr << " "                <<c << endl;
       ctr++;
    }
    ctr = 1;
    cout << flush;
   }
