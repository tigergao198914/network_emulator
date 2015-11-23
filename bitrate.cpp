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
    list<std::auto_ptr<Packet>> _packets;
    int bytesAccumulate;
};

Bitrate::Bitrate()
{
    bytesAccumulate = 0;
}

Bitrate::~Bitrate()
{
}

int Bitrate::getBitrateBps()
{
     return bytesAccumulate/2000;
}

int Bitrate::input(int packetLen)
{
    long long current_time_ms = getCurTimeStampMs();
    std::auto_ptr<Packet> packet = new Packet(packetLen, current_time_ms);
    _packets.push_back(packet);
    bytesAccumulate += packetLen;
    for(any it=list.begin(); it!=list.end(); it++)
    {
        if( current_time_ms - it->timeStamp < 2000 )
        {
            break;
        }
        list.remove(it);
        bytesAccumulate -= it->bytes;
    }
}
