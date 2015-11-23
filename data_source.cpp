
class DataSource
{
public:
    DataSource();
    ~DataSource();
    void setTargetBitrate(int targetBitrateBps);
    typedef void (*OnGenerateDataCallback)(void *data, int len);
    void registOnGenerateDataCallback( OnGenerateDataCallback callback );
    void start();
    void stop();
private:
    int _targetBitrateBps;
    OnGenerateDataCallback _callback;
    void generate(void **data, int *len);
    bool _bRuning;
};

DataSource::DataSource()
{
    _targetBitrateBps = -1;
    _callback  = NULL;
    _bRuning = false;
}

DataSource::~DataSource()
{

}

void DataSource::setTargetBitrate(int targetBitrateBps)
{
    _targetBitrateBps = targetBitrateBps;
}

void DataSource::registOnGenerateDataCallback( OnGenerateDataCallback callback )
{
    _callback = callback;
}

void DataSource::generate(void **data, int *len, int *nextTimeInterval)
{
    //generate next packet time according to possion(lamda)
    //generate size of next packet according to beta(a,b)

}

void DataSource::start()
{
    _bRuning = true;
    void *data = NULL;
    int len = 0;
    int nextTimeInterval = 0;
    while( _bRuning )
    {
        generate( &data, &len, &nextTimeInterval);

        if( _callback )
        {
            _callback(data, len );
        }
    }
}

void DataSource::stop()
{
    _bRuning = false;
}


