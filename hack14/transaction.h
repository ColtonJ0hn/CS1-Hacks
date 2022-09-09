typedef struct {
    char *UUID;
    char *type;
    double amount;
    char *accountNumber;
    double beforeBalance;
    double afterBalance;
    char *transferAccountNumber;
} Transaction;


/**
 * creates a deep copy of a string
 */
char * deepStringCopy(const char * s);

/**
 * fills a structure with variables
 */
void initTransaction(Transaction * transaction,
                     char *UUID,
                     char *type,
                     double amount,
                     char *accountNumber,
                     double beforeBalance,
                     double afterBalance,
                     char *transferAccountNumber);

/**
 * transfers strings to a bunch of variables
 */
Transaction stringToTransaction(char *buffer);


//void printOneStructure(const Transaction singleTrans);


/**
 * prints out the report of totals and amounts
 */
void printReport(int paymentCount, int transferCount, int withdrawCount,int debitCount, int depositCount, int totalCount,
                 double totalPayment, double totalTransfer, double totalWithdraw, double totalDebit, double totalDeposit,
                 double totalAmount);

/**
 * Prints out a report validating transactions
 */
void printValidationReport(const Transaction *transactions, int k, double invalidDifference);
/**
 * prints out a report of FFA laws of depositing
 */
void printDepositLimitReport(int depositApproaching, int depositExceeding);

/**
 * Prints out a report of repeated transactions, same amount transfer and account numbers
 */
void printRepeatedTransactions(const Transaction *transactions, int i);

/**
 * loads a CSV file and puts it into a structure
 */
Transaction * loadFile(const char *fileName, int *numTransactions);
/**
 * compares amounts, before balances, and after balances
 */
int cmpByRepeatedTransaction(const void* a, const void* b);
/**
 *compares everything in the structure
 */
int cmpByAll(const void* a, const void* b);
/**
 * compares an array by UUID and puts it alphabetically
 */
int cmpByUUID(const void* a, const void* b);
/**
 * prints out a report of Benford Analysis's
 */
void printBenfordAnalysis(int i, int benfordNumber, double exactFrequency,
                          double expectedFrequency, double benfordDifference);


