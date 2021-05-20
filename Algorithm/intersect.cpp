#include "TripleBit.h"
#include "HashID.h"
#include "TempFile.h"

int main(int argc, char* argv[])
{
	if(argc != 3) {
		fprintf(stderr, "Usage: %s <Database Directory> <vertex_pair file>\n", argv[0]);
		return -1;
	}

	struct timeval start_time, end_time;
	gettimeofday(&start_time, NULL);
	
	MemoryMappedFile adjfile;
	assert(adjfile.open((string(argv[1])+"/range_adjlist.0").c_str()));
	const char *adj_ptr = adjfile.getBegin();
	
	MemoryMappedFile adjoffset;
	assert(adjoffset.open((string(argv[1])+"/range_adjoffset.0").c_str()));
	startid_offset *offset_arr = (startid_offset *)adjoffset.getBegin();
	
	MemoryMappedFile adjoffset_index;
	assert(adjoffset_index.open((string(argv[1])+"/range_adjoffset_index.0").c_str()));
	unsigned len = adjoffset_index.getEnd() - adjoffset_index.getBegin(), size = len / sizeof(startid_offset_index);
	char *offset_index = (char *)malloc(len);
	memcpy(offset_index, adjoffset_index.getBegin(), len);
	startid_offset_index *offset_index_arr = (startid_offset_index *)offset_index;
	
	MemoryMappedFile old_mapto_new;
	assert(old_mapto_new.open((string(argv[1])+"/old_mapto_new.0").c_str()));
	ID *oldID_mapto_newID = (ID *)old_mapto_new.getBegin();
	
	ID vertex1, vertex2;
	bool hit;
	freopen(string(argv[2]).c_str(), "r", stdin);
	while(scanf("%d %d", &vertex1, &vertex2) != EOF){
		//HashID::intersect_or_not(oldID_mapto_newID[vertex1], oldID_mapto_newID[vertex2], offset_index_arr, size, offset_arr, adj_ptr);
		hit = HashID::intersect_or_not(vertex1, vertex2, offset_index_arr, size, offset_arr, adj_ptr);
		if(hit)cout<<"vertex "<<vertex1<<" and vertex "<<vertex2<<" intersect!"<<endl;
		else cout<<"vertex "<<vertex1<<" and vertex "<<vertex2<<" not intersect!"<<endl;
		cout<<endl;
	}
	
	adjfile.close();
	adjoffset.close();
	adjoffset_index.close();
	old_mapto_new.close();
	fclose(stdin);
	free(offset_index);
	
	gettimeofday(&end_time, NULL);
	cout<<"time elapse: "<<((end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec)) / 1000000.0<<" s"<<endl;
	return 0;
}
