#ifndef TEST_H
#define TEST_H



class Test{

	public:

		Test();
		~Test();

		virtual int InitMySQL(void);

		virtual int CreateServerTable(void);
		virtual int DeleteServerTable(void);

		virtual int CreateDmaTable(void);
		virtual int DeleteDmaTable(void);

		virtual int ReadDmaTable(void);
		virtual int ReadLastId(void);
		virtual int InsertIntoDmaTable(void);
		virtual int DeleteFormDmaTable(void);
		virtual int DeleteDatabase(void);
		
};

#endif /* TEST_H */
