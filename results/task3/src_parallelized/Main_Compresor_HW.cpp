#ifdef VERBOSE
#include <iostream>
#include <fstream>
#include <sstream>

#include <sys/stat.h> 
#include <sys/types.h> 

using namespace std;
#endif


#include <omp.h>
#include "HyperLCA_Transform_Operations.h"


// --- Function Signatures
void read_Integer_Matrix(char* inputFileName, unsigned short *input_img);
void write_binary_file(char* OutputFileName, unsigned short *compressed_stream, unsigned int written_bytes);
void runCompressor(unsigned short *input_img, FILE* OutputFileName);		


// --- Main
int main(int argc, char* argv[])
{
#ifdef VERBOSE
  mkdir("output", 0777);
#endif

  // Input Img
  unsigned short *input_img;
  input_img = (unsigned short *)malloc(sizeof(unsigned short)*IMAGE_SIZE);
  //unsigned short input_img[IMAGE_SIZE];  
  
  // Read the Img
  read_Integer_Matrix((char*)INPUT_FILE_NAME, input_img);

  // Run the compressor
  FILE * outputFile = fopen((char*)OUTPUT_FILE_NAME, "wb");
  runCompressor(input_img, outputFile);
  fclose (outputFile);

  //Write compressed stream
  // It is done for each block
  
  printf("\n -- Finished OK -- \n\n\n");

  free(input_img);
	
  return 0;	
}


void read_Integer_Matrix(char* inputFileName, unsigned short *input_img)
{
  FILE * inputFile = fopen(inputFileName, "r+b");
  
  int numberOfReadElement = 0;
  int bytesPerElement = 2;

  unsigned short readElements[READ_BUFF_SIZE];

  int elements_actually_read;
  
  while ( numberOfReadElement < IMAGE_SIZE) {
    elements_actually_read = fread(readElements, bytesPerElement, READ_BUFF_SIZE, inputFile);
    memcpy(input_img + numberOfReadElement, readElements, elements_actually_read * bytesPerElement);
    numberOfReadElement += elements_actually_read;
  }
  fclose (inputFile);
}


// Function for writting one specific binary bitsream to a file
void write_binary_file(FILE* outputFile, unsigned short *compressed_stream, unsigned int nbytes, unsigned int blockIndex)
{
  #pragma omp critical
  {
    fseek (outputFile, blockIndex * sizeof(short) * nbytes, SEEK_SET);
    fwrite (compressed_stream , sizeof(short), nbytes, outputFile);
  }
}



// Function for executing the process
void runCompressor(unsigned short *input_img, FILE* OutputFile)		
{
  // Initialize and declare the variables
  unsigned int nBlocks = (COLUMNS*LINES) / BLOCK_SIZE;
  unsigned int nInputElementsPerBlock = BLOCK_SIZE*BANDS;
  
  unsigned short input_block[BLOCK_SIZE * BANDS];	
  unsigned short trasformOutputData[BANDS+(BANDS + BLOCK_SIZE)*PMAX];
  
  unsigned int inputIndex = 0;

  #pragma omp parallel for private(input_block, trasformOutputData, inputIndex) schedule(dynamic)
  for(int blockIndex = 0; blockIndex < nBlocks; blockIndex++){
    // Creating the block vector
    inputIndex = blockIndex * nInputElementsPerBlock;
    for(int elementIndex=0; elementIndex<nInputElementsPerBlock; elementIndex++){
      input_block[ elementIndex ] = input_img[ inputIndex + elementIndex ];
    }
		
    HyperLCA_transform(blockIndex, input_block, trasformOutputData);

		
#ifdef VERBOSE
    if (blockIndex == BLOCK_DBG || BLOCK_DBG==-1){
      stringstream filenameG;
      filenameG << "output/b" << blockIndex << ".txt";
      ofstream goldenFile;
      goldenFile.open(filenameG.str());
      for(int it=0; it !=BANDS+((BLOCK_SIZE+BANDS)*PMAX); it++)
	goldenFile << trasformOutputData[it] << endl;
      goldenFile.close();
    }
#endif
		
    // Write the block bitstream to a file
    write_binary_file(OutputFile, trasformOutputData, (BANDS+(BANDS+BLOCK_SIZE)*PMAX), blockIndex);
  }
}
