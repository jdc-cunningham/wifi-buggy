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

    if (espMsg.indexOf("m_f") > -1) // index of due to char chunking
    {
      activeDirection = "forward";
    }

    if (espMsg.indexOf("m_l") > -1) // index of due to char chunking
    {
      activeDirection = "left";
    }

    if (espMsg.indexOf("m_r") > -1) // index of due to char chunking
    {
      activeDirection = "right";
    }

    if (espMsg.indexOf("m_b") > -1) // index of due to char chunking
    {
      activeDirection = "back";
    }

    if (espMsg.indexOf("m_s") > -1) // move stop?
    {
      activeDirection = "";
    }

    clearEspSerial();
  }

  // Serial.println("check");

  delay(250); // delay for sync
}
