#include <stdio.h>
#include <string.h>
#include <curl.h>
#include <json.h>
#include <api_key.h>

typedef struct {
    char titolo[50];
    char autore[50];
    float prezzo;
} Libro;

Libro cercaLibro(char *titolo);
void aggiungiLibro(Libro libro);
Libro ottieniDettagliLibro(char *idLibro);
size_t WriteCallback(void *contents, size_t size, size_t numel, void *userp);

size_t WriteCallback(void *contents, size_t size, size_t nmemb, char *userp){
    size_t totalSize = size * nmemb;
    strncat(userp, contents, totalSize);
    return totalSize;
}

Libro cercaLibro(char *titolo) {
    //richiesta all'API di ricerca di libri
    CURL *curl;
    CURLcode res;
    char readBuffer[8192] = {0};

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.notion.com/v1/database/2aadd6548a4e4199939de3bfccdbc06b");//diff con search?

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Authorization: Bearer %s", EVA_API_KEY);
        headers = curl_slist_append(headers, "Notion-Version: 2022-02-22");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);//lista di header HTTP

        json_object *jobj = json_object_new_object();
        json_object *jstring = json_object_new_object(titolo);//creazione di un oggetto json con titolo del libro e impostarlo come corpo della richiesta
        json_object_object_add(jobj,"query", jstring);
        const char *json_str = json_object_to_json_string(jobj);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback());//la funzione gestisce dati ricevuti
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);//buffer dove salvare i dati

        res = curl_easy_perform(curl);//risultato richiesta HTTP salvato in res

        if(res != CURLE_OK)//verifica errori
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        else {
            printf("%s\n", readBuffer);

            //gestire risposta JSON
            json_object *parsed_json;
            parsed_json = json_tokener_parse(readBuffer);
            //crea nuovo libro
            Libro libro;
            strcpy(libro.titolo, json_object_get_string(json_object_object_get(parsed_json, "Titolo")));
            strcpy(libro.autore, json_object_get_string(json_object_object_get(parsed_json, "Autore")));
            libro.prezzo = json_object_get_double(json_object_object_get(parsed_json, "Prezzo");
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();//pulire libcurl
    //restituire nuovo Libro
    return libro;
}

