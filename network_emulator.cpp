
class Bitrate
{
public:
    Bitrate();
    ~Bitrate();
    int getBitrateBps();
    int input(int packetLen);
private:
    class Packet
    {
    private:
        long long _timeStamp;
        int _packetLen;
        int _bitrateBps;
    public:
        Packet(packetLen, timeStamp)
        {
            _packetLen = packetLen;
            _timeStamp = timeStamp;
        }
        ~Packet(){}
    };
    vector<std::auto_ptr<Packet>> packets;
};

Bitrate::Bitrate()
{

}

Bitrate::~Bitrate()
{

}

int Bitrate::getBitrateBps()
{

}

int Bitrate::input(int packetLen)
{

}

class NetworkCondition
{
public:
    NetworkCondition();
    ~NetworkCondition();
    void setNetworkCondition(int bandwidth, int delay, int jitter, int lostRate);
private:
    enum
    {
        NetworkUnlimited=-1
    };

    int _bandwidth;
    int _delay;
    int _jitter;
    int _lostRate;
};

NetworkCondition::NetworkCondition()
{
    _bandwidth = NetworkUnlimited;
    _delay     = NetworkUnlimited;
    _jitter    = NetworkUnlimited;
    _lostRate  = NetworkUnlimited;
}

NetworkCondition::~NetworkCondition()
{

}

void NetworkCondition::setNetworkCondition(int bandwidth, int delay, int jitter, int lostRate)
{
    assert(bandwidth>0&&delay>0&&jitter>0&&lostRate>0);
    _bandwidth = bandwidth;
    _delay     = delay;
    _jitter    = jitter;
    _lostRate  = lostRate;
}

class NetworkEmulator
{
public:
    NetworkEmulator();
    ~NetworkEmulator();
    int sendData(void* data, int len);
    typedef void (*OnReceiveDataCallback) (void* data, int len);
    int registerOnReceiveDataCallback(OnReceiveDataCallback callback);
    int setNetworkCondition(int bandwidth, int delay, int jitter, int lostRate);
    int getNetworkEmulatorStatus(int *bufferedPacketNum, int *bufferedDataLen, int *incomingBitrate, int *outcomingBitrate);
private:
    class DataPacket
    {
    private:
        void *_data;
        int _len;
        long long _timeStamp;
    public:
        inline DataPacket(void *data, int len, long long timeStamp)
        {
            _data = data;
            _len  = len;
            _timeStamp = timeStamp;
        }
    };
    NetworkCondition _networkCondition;
    OnReceiveDataCallback _onReceiveDataCallback;
    vector<std::any> _networkQueue;
};

NetworkEmulator::NetworkEmulator()
{
    _onReceiveDataCallback = NULL;
}

int NetworkEmulator::sendData(void* data, int len)
{
    long long current_time_ms = getCurTimeStampMs();
    std::auto_ptr<DataPacket> packet = new DataPacket( data, len, current_time_ms );
    _networkQueue.push_back(packet);
}

int NetworkEmulator::registerOnReceiveDataCallback(OnReceiveDataCallback callback)
{
    _onReceiveDataCallback = callback;
}

int NetworkEmulator::setNetworkCondition(int bandwidth, int delay, int jitter, int lostRate)
{
    _networkCondition.setNetworkCondition(bandwidth, delay, jitter, lostRate);
}

int NetworkEmulator::getNetworkEmulatorStatus(int *bufferedPacketNum, int *bufferedDataLen, int *incomingBitrate, int *outcomingBitrate);
{

}




