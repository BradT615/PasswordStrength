//Password Strength Meter

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void resultWithoutOptional(int requiredCount[], int maxLength, int minLength){
  int passCounter = 0;
  for(int i = 0; i < 7; i++){
    if(requiredCount[i] == 1){
      passCounter++;
    }
  }
  int failCounter = 7 - passCounter;
  printf("Failed Tests: %d\n", failCounter);
  printf("Passed Tests: %d\n", passCounter);
  
  printf("Required Test Errors:[\n");
  if(requiredCount[0] == 0){
    printf("\tThe password must be at least %d characters long.\n", minLength);
  }
  if(requiredCount[1] == 0){
    printf("\tThe password must be fewer than %d characters.\n", maxLength);
  }
  if(requiredCount[2] == 0){
    printf("\tThe password may not contain sequence of three or more repeated characters.\n");
  }
  printf("\t\t]\n");

  printf("Is a Pass phrase: false\n");
  
  if(passCounter == 3){
    printf("Strong?: true\n");
  }
  else{
    printf("Strong?\t\t\t: false\n");
  }
}

void result(int requiredCount[], int optionalCount[], int pass, int maxLength, int minLength){
  int passCounter = 0;
  int requiredCounter = 0;
  int optionalCounter = 0;
  for(int i = 0; i < 7; i++){
    if(requiredCount[i] == 1){
      passCounter++;
      requiredCounter++;
    }
    if(optionalCount[i] == 1){
      passCounter++;
      optionalCounter++;
    }
  }
  int failCounter = 7 - passCounter;
  printf("Failed Tests: %d\n", failCounter);
  printf("Passed Tests: %d\n", passCounter);
  
  printf("Required Test Errors:[\n");
  if(requiredCount[0] == 0){
    printf("\tThe password must be at least %d characters long.\n", minLength);
  }
  if(requiredCount[1] == 0){
    printf("\tThe password must be fewer than %d characters.\n", maxLength);
  }
  if(requiredCount[2] == 0){
    printf("\tThe password may not contain sequence of three or more repeated characters.\n");
  }
  printf("\t\t]\n");

  printf("Optional Test Errors:[\n");
  if(optionalCount[0] == 0){
    printf("\tThe password must contain at least one lowercase letter.\n");
  }
  if(optionalCount[1] == 0){
    printf("\tThe password must contain at least one uppercase letter.\n");
  }
  if(optionalCount[2] == 0){
    printf("\tThe password must contain at least one number.\n");
  }
  if(optionalCount[3] == 0){
    printf("\tThe password must contain at least one special character.\n");
  }
  printf("\t\t]\n");
  
  /* Checks if Pass Phrase */
  if(pass == 0){
    printf("Is a Pass Phrase: False\n");
  }
  else{
    printf("Is a Pass Phrase: True\n");
  }

  if(optionalCounter > 2){
    printf("Strong?: true\n");
  }
  else{
    printf("Strong?\t\t\t: false\n");
  }
  printf("Total optional tests passed: %d\n", optionalCounter);
  
}
/* Tests Optional Tests */
int *optionalTests(char password[80], int passwordLength, int optionalTestsNum){
  /* Holds Optional Tests Results  */
  static int optionalCount[4] = {0,0,0,0};
  
  /* [4] Contains at least one lowercase letter  */
  /* [5] Contains at least one uppercase letter */
  /* [6] Contains at least one digit  */
  /* [7] Contains at least one special character (not alpha, not digit)  */
  for(int i = 0; i < passwordLength; i++){
    int passwordChar = password[i];
      if(passwordChar != 32){
      if(passwordChar <= 122 && passwordChar >= 97){
        optionalCount[0] = 1;
      }
      if(passwordChar <= 90 && passwordChar >= 65){
        optionalCount[1] = 1;
      }
      if(passwordChar <= 57 && passwordChar >= 48){
        optionalCount[2] = 1;
      }
      if((passwordChar >= 33 && passwordChar <= 47) || 
        (passwordChar >= 58 && passwordChar <= 64)  ||
        (passwordChar >= 91 && passwordChar <= 96)  ||
        (passwordChar>= 123 && passwordChar <= 126)){
          optionalCount[3] = 1;
      }
    }
  }
    return optionalCount;
}
/* Tests Pass Phrase */
int passPhraseTest(char password[], int passwordLength, int minPassPhraseLength){
  int passPhrase;
  if(passwordLength > minPassPhraseLength){
    passPhrase = 1;
  }
  return passPhrase;
}
/* Tests Required Tests */
void requiredTests(char password[], int flags[]){

  /* Declare Flags */
  int maxLength = flags[0];
  int minLength = flags[1];
  int allowPassPhrases = flags[2];
  int minPassPhraseLength = flags[3];
  int requireOptionalTests = flags[4];
  int optionalTestsNum = flags[5];

  printf("\n\n\nPotential password: %s", password);
  /* Holds Required Test Results  */
  int requiredCount[4] = {0,0,1,0};
  int passwordLength = strlen(password) - 2;

  /* [1] Enforce a minimum length */
  if(passwordLength > minLength){
    requiredCount[0] = 1;
  }
  /* [2] Enforce a maximum length */
  if(passwordLength < maxLength){
    requiredCount[1] = 1;
  }
  /* [3] Forbid repeats */
  if(passwordLength > 3){
    for(int i = 1; i < passwordLength; i++){
      if(password[i-1] == password[i] && password[i] == password[i+1]){
        requiredCount[2] = 0;
      }
    }
  }
  /* calls passPhrase function */
  int pass = 0;
  if(allowPassPhrases == 1){
    pass = passPhraseTest(password, passwordLength, minPassPhraseLength);
  }
  /* calls  function */
  static int *optionalCount;
  if(requireOptionalTests == 1){
    optionalCount = optionalTests(password, passwordLength, optionalTestsNum);
  }
  if(allowPassPhrases == 1){
    result(requiredCount, optionalCount, pass, maxLength, minLength);
    optionalCount[0] = 0;
    optionalCount[1] = 0;
    optionalCount[2] = 0;
    optionalCount[3] = 0;
    }
  else{
    resultWithoutOptional(requiredCount, maxLength, minLength);
  }
}
/* stores password */
void findPassword(FILE *dataFile,char fileName[], int flags[]){
  
  /* Open and Check File */
  dataFile = fopen(fileName, "r");
  if (dataFile == NULL) {
    printf("Error opening File \n");
    exit(1);
  }
  
  int trash; /* holds flag */
  char password[80]; /* holds password */
  
  while((fscanf(dataFile, "%d", &trash)) == 1){
  }
  while(fgets(password, 80, dataFile)){
    requiredTests(password, flags);
  }
}
/* pulls and prints flags */
void flags(FILE *dataFile, int fileNumber) {

  char fileName[50] = "Proposed passwords #";
  char second[] = ".txt";
  char number = (char)(fileNumber + '0');
  strncat(fileName, &number, 1);
  strcat(fileName, second);

  printf("\n\nProcessing password file #%d\n\n", fileNumber);
  /* Open and Check File */
  dataFile = fopen(fileName, "r");
  if (dataFile == NULL) {
    printf("Error opening File \n");
    exit(1);
  }

  int flags[6];
  for (int i = 0; i < 6; i++) {
    int flagValue;
    fscanf(dataFile, "%d", &flagValue);
    flags[i] = flagValue;
  }
  printf("Maximum password length: %d\n", flags[0]);
  printf("Minimum password length: %d\n", flags[1]);
  if (flags[2] == 0) {
    printf("Pass phrases are NOT allowed\n");
  } else {
    printf("Pass phrases are allowed\n");
    printf("Minimum pass phrase length: %d\n", flags[3]);
  }
  if (flags[4] == 0) {
    printf("Optional Tests are NOT allowed\n\n");
  } else {
    printf("Optional Tests are allowed\n");
    printf("Number of Optional Tests required: %d\n", flags[5]);
  }
  findPassword(dataFile, fileName, flags);
}
/* calls flags function */
int main(void) {

  FILE *dataFile;
  
  flags(dataFile, 1);
  flags(dataFile, 2);
  flags(dataFile, 3);
  return 0;
}