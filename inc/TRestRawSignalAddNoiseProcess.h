/*************************************************************************
 * This file is part of the REST software framework.                     *
 *                                                                       *
 * Copyright (C) 2016 GIFNA/TREX (University of Zaragoza)                *
 * For more information see http://gifna.unizar.es/trex                  *
 *                                                                       *
 * REST is free software: you can redistribute it and/or modify          *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * REST is distributed in the hope that it will be useful,               *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have a copy of the GNU General Public License along with   *
 * REST in $REST_PATH/LICENSE.                                           *
 * If not, see http://www.gnu.org/licenses/.                             *
 * For the list of contributors see $REST_PATH/CREDITS.                  *
 *************************************************************************/

#ifndef RestCore_TRestRawSignalAddNoiseProcess
#define RestCore_TRestRawSignalAddNoiseProcess

#include <TRestEventProcess.h>

#include "TRestRawSignalEvent.h"

//! A process to add/emulate electronic noise into a TRestRawSignalEvent
class TRestRawSignalAddNoiseProcess : public TRestEventProcess {
   private:
    TRestRawSignalEvent* fInputSignalEvent;
    TRestRawSignalEvent* fOutputSignalEvent;

    void Initialize() override;

    void LoadDefaultConfig();

    Double_t fNoiseLevel = 10.0;

   protected:
    // add here the members of your event process

   public:
    inline Double_t GetNoiseLevel() const { return fNoiseLevel; }
    inline void SetNoiseLevel(Double_t noiseLevel) { fNoiseLevel = noiseLevel; }

    any GetInputEvent() const override { return fInputSignalEvent; }
    any GetOutputEvent() const override { return fOutputSignalEvent; }

    void InitProcess() override;
    TRestEvent* ProcessEvent(TRestEvent* inputEvent) override;
    void EndProcess() override;

    void LoadConfig(const std::string& configFilename, const std::string& name = "");

    inline void PrintMetadata() override {
        BeginPrintProcess();

        RESTMetadata << "Noise Level : " << fNoiseLevel << RESTendl;

        EndPrintProcess();
    }

    TRestMetadata* GetProcessMetadata() const { return nullptr; }

    const char* GetProcessName() const override { return "rawSignalAddNoise"; }

    // Constructor
    TRestRawSignalAddNoiseProcess();
    TRestRawSignalAddNoiseProcess(const char* configFilename);
    // Destructor
    ~TRestRawSignalAddNoiseProcess();

    ClassDefOverride(TRestRawSignalAddNoiseProcess, 1);
};
#endif
