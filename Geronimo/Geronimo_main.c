#include <stdio.h>
#include <curl/curl.h>
#include <json-c/json.h>

typedef struct {
    char titolo[50];
    char autore[50];
    float prezzo;
} Libro;

Libro cercaLibro(char *titolo);
void aggiungiLibro(Libro libro);
Libro ottieniDettagliLibro(char *idLibro);
size_t WriteCallback(void *contents, size_t size, size_t numel, void *userp);

Libro cercaLibro(char *titolo) {
    //richiesta all'API di ricerca di libri
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.notion.com/v1/database/2aadd6548a4e4199939de3bfccdbc06b");//diff con search?

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Authorization: Bearer ");
        headers = curl_slist_append(headers, "Notion-Version: 2022-02-22");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        json_object *jobj = json_object_new_object();
        json_object *jstring = json_object_new_object(titolo);
        json_object_object_add(jobj,"query", jstring);
        const char *json_str = json_object_to_json_string(jobj);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    }
    //gestire risposta JSON e creare un nuovo Libro
    //restituire nuovo Libro
}

void aggiungiLibro(Libro libro) {
    //creare JSON con i dettagli del libro
    //richiesta POST all'API di Notion con il JSON
}

Libro ottieniDettagliLibro(char *idLibro) {
    //richiesta GET all'API di Notion con l'ID del libro
    //gestire la risposta JSON e crea un nuovo Libro
    //restituire nuovo Libro
}

//funzione per gestire la risposta dell'API
size_t WriteCallback(void *contents, size_t size, size_t numel, void *userp){
    ((std::string*)userp)->append((char*)contents, size * numel);
    return size * nmemb;
}