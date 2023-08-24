// compile - gcc write_to_file.c -ljson-c -o write-to-file

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <json-c/json.h>

#define DB_LOCATION "/data/gpr3hi/code-space/c/json-c/file.txt"


void create_db_entry(const char* name, const uint8_t age)
{
    FILE* fp;
    const char* serialized_json;
    fp = fopen (DEFAULT_STATUS_FILE_PATH, "wb");
    if (fp)
    {
        json_object* j_obj = json_object_new_object();
        json_object_object_add(j_obj, "Name", json_object_new_string(name));
        json_object_object_add(j_obj, "Age", json_object_new_int((int32_t)age));

        serialized_json = json_object_to_json_string(j_obj);

        if (!fwrite(serialized_json, sizeof(char), strlen(serialized_json), fp)) 
        {
            printf("Failed to write to %s file", DB_LOCATION);
        }

        json_object_put(j_obj);
    }

    fclose(fp);
}

int main()
{
    create_db_entry("Name", 32);
    return 0;
}
