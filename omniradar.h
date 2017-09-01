#pragma once

#include <stdexcept>
#include <stdint.h>
#include <vector>
#include <string>

struct _RDK_Handle;
typedef struct _RDK_Handle *RDK_Handle;

class OmniradarException : public std::runtime_error
{
public:
    explicit OmniradarException (const std::string &description) :
    std::runtime_error(description) { }
};

class Omniradar
{
public:
    Omniradar(uint32_t index = 0);
    ~Omniradar();

    uint32_t ReadRegister(uint32_t address);
    void WriteRegister(uint32_t address, uint32_t content);
    std::string ConfigureRadar(std::string settings_string, bool use_legacy_header = false);
    double SetReferenceClock(uint32_t m_multiplier, uint32_t n_divisor, uint32_t c0_post);
    void setSweepTime(double sweep_time);
    void setVCOTune(std::vector<double> samples, bool enable_vtune_1 = true, bool enable_vtune_2 = true);
    std::shared_ptr< std::vector<uint32_t> > AcquireEcho(uint32_t n_sweeps = 1);
    std::shared_ptr< std::vector<uint32_t> > AcquireEchoDiv(uint32_t n_sweeps = 1, int v_start = 1, int v_stop = 1, int t_step = 1);
    bool GetP0();
    void SetP0(bool setting);
    void ResetRadar();
    uint32_t FirmwareVersion();
    uint32_t getMeterCount();
    void setMeterPeriod(double period);
    
    static std::shared_ptr< std::vector<std::vector<uint8_t> > > demultiplex(std::vector<uint32_t> &packed_data);

private:
    RDK_Handle *device_handle = nullptr;
};
