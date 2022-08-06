#define ESPSERIAL Serial1

// used to avoid buffer buildup between ESP and web communication delay
String curEspMsg = "";

void setupEspSerial()
{
  ESPSERIAL.begin(115200);
}

void clearEspSerial()
{
  while (ESPSERIAL.available() > 0)
  {
    ESPSERIAL.read();
  }
}

String getEspSerialMsg() {
  if (ESPSERIAL.available() > 0) {
    String msg = ESPSERIAL.readString();
    return msg;
  }

  return "";
}

void writeToEsp(String msg)
{
  if (curEspMsg.length() == 0)
  {
    curEspMsg = msg;
    ESPSERIAL.print(msg);
    ESPSERIAL.flush();
    curEspMsg = "";
  } else
  {
    Serial.println("esp write err");
  }
}

void checkMessages()
{
  // poll is like a keep-alive, it bunches up due timing mismatch
  String espMsg = getEspSerialMsg();
  
  if (espMsg)
  {
    espMsg.replace("poll", "");
    espMsg.replace("Hello Server!", "");
  }

  if (espMsg)
  {
    Serial.println(espMsg);

    if (espMsg == "mf")
    {
      moveForward();
    }

    clearEspSerial();
  }

  delay(250); // delay for sync
}
