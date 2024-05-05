#include <ESP8266WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#include <Timezone.h>

// Datos de conexión a la base de datos
const char* server = "bm6rbuii3pvzukrbv2az-mysql.services.clever-cloud.com"; // Host de tu servidor MySQL en Clever Cloud
char* user = "u0a4peehlug7lif1"; // Usuario de la base de datos
char* password = "2cjaFqGaAUXrCmvpe41q"; // Contraseña de la base de datos
char* db = "bm6rbuii3pvzukrbv2az"; // Nombre de la base de datos
const int port = 3306; // Puerto de MySQL
// Variables para la conexión WiFi
const char* ssid = "CLARO-77C0"; // Nombre de tu red WiFi
const char* password_wifi = "Cl4r0@6777C0"; // Contraseña de tu red WiFi



// Objeto para la sincronización de tiempo NTP
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org"); // Horario de verano termina en el último domingo de octubre


// Objeto para la conexión MySQL
WiFiClient client;
MySQL_Connection conn((Client *)&client);

void setup() {
   
  Serial.begin(9600);
  delay(100);

  // Conexión a la red WiFi
  Serial.println();
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password_wifi);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());

  IPAddress resolvedIP;
    if (WiFi.hostByName(server, resolvedIP)) 
    {
        Serial.print("Dirección IP resuelta: ");
        Serial.println(resolvedIP);
    } 
    else 
    {
        Serial.println("Error en la búsqueda DNS.");
    }
  // Conexión a la base de datos MySQL
  Serial.println("Conectando a la base de datos MySQL...");

  if (conn.connect(resolvedIP, port, user, password, db)) 
  {
    Serial.println("Conexión exitosa a la base de datos MySQL");
  }
  else 
  {
    Serial.println("Error de conexión a la base de datos MySQL");
    return;
  }
  
}

void loop() {


MySQL_Cursor cur_mem(&conn); // Mover la creación del cursor fuera del loop


/*
independiente de lo que se valla hacer recuerda la asincronia 
git */


 /*
   // Actualizar la hora y la fecha
  timeClient.update();
  time_t rawtime = timeClient.getEpochTime() - (5 * 3600); // Restar 5 horas en segundos para ajustar a la zona horaria de Colombia


  // Convertir la hora actual a una estructura tm
  struct tm *tiempo = localtime(&rawtime);

  // Formatear la hora
  char formattedTime[20];
  sprintf(formattedTime, "%02d:%02d:%02d", tiempo->tm_hour, tiempo->tm_min, tiempo->tm_sec);

  // Formatear la fecha
  char formattedDate[20];
  sprintf(formattedDate, "%04d-%02d-%02d", tiempo->tm_year + 1900, tiempo->tm_mon + 1, tiempo->tm_mday);

  // Mostrar la hora y la fecha
  Serial.print("Hora de Colombia: ");
  Serial.print(formattedTime);
  Serial.print(", Fecha: ");
  Serial.println(formattedDate);

  delay(10000); // Esperar 10 segundos antes de volver a leer la hora y la fecha
*/



/*
/////////////////////////////////////////////////////////////////////////////
Agregar DAtaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
////////////////////////////////////////////////////////////////////////////////
Serial.println("agregando datos de la tabla Users:");

// Crear un objeto cursor para ejecutar la consulta
     // Espera 5 segundos antes de ejecutar la siguiente inserción
    // MySQL_Cursor cur_mem(&conn); // Esto debe estar fuera del loop si no quieres crear un nuevo cursor cada vez

    String names = "cancan";
    String lastnames = "ssssss";
    String nickname = "sssssssssss";
    String email = "rrrrrrrrrr@.com";
    String phone = "123456789";
    String observations = "Sin observaciones";

    String insert_query = "INSERT INTO Users (Names, LastNames, Nickname, Email, Phone, Observaciones) VALUES ('" + names + "', '" + lastnames + "', '" + nickname + "', '" + email + "', '" + phone + "', '" + observations + "')";

    const char* insert_query_cstr = insert_query.c_str();

    

    if (cur_mem.execute(insert_query_cstr)) {
        Serial.println("Nuevo usuario agregado correctamente.");
    } else {
        Serial.println("Error al agregar nuevo usuario.");
    }


}
*/


/*
////////////////////////////////////////////////////////////////////////////////////////////////////
Leer Dataaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
/////////////////////////////////////////////////////////////////////////////////////////////////
Serial.println("Leyendo datos de la tabla Users:");


// Ejecutar la consulta
if (cur_mem.execute("SELECT * FROM Users")) {
    // Leer las columnas primero
    column_names *cols = cur_mem.get_columns();

    // Verificar si se leyeron las columnas correctamente
    if (cols != NULL) {
        // Leer y mostrar los resultados
        bool more_rows = true; // Bandera para determinar si hay más filas
        while (more_rows) {
            // Obtener la siguiente fila
            row_values *row = cur_mem.get_next_row();

            // Verificar si la fila es válida
            if (row != NULL) {
                // Iterar sobre los valores de la fila
                for (int i = 0; i < cols->num_fields; i++) {
                    // Verificar si el valor es nulo
                    if (row->values[i] != NULL) {
                        // Imprimir el valor
                        Serial.print(row->values[i]);
                    } else {
                        // Imprimir NULL si el valor es nulo
                        Serial.print("NULL");
                    }
                    Serial.print("\t"); // Separador de columnas
                }
                Serial.println(); // Nueva línea para la siguiente fila
            } else {
                // No hay más filas disponibles, establecer la bandera en falso
                more_rows = false;
            }
        }
    } else {
        // Ocurrió un error al leer las columnas
        Serial.println("ERROR: Failed to read columns!");
    }
}
else 
{
  Serial.println("Error al ejecutar la consulta");
};
*/

}




