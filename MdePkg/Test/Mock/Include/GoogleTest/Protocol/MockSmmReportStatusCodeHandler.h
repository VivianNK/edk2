/** @file MockSmmReportStatusCodeHandler.h
  This file declares a mock of SMM Report Status Code Handler Protocol.

  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#ifndef MOCK_SMM_REPORT_STATUS_CODE_HANDLER_PROTOCOL_H
#define MOCK_SMM_REPORT_STATUS_CODE_HANDLER_PROTOCOL_H

#include <Library/GoogleTestLib.h>
#include <Library/FunctionMockLib.h>

extern "C" {
  #include <Uefi.h>
  #include <Library/ReportStatusCodeLib.h>
  #include <Protocol/SmmReportStatusCodeHandler.h>
}

struct MockSmmReportStatusCodeHandler {
  MOCK_INTERFACE_DECLARATION (MockSmmReportStatusCodeHandler);

  MOCK_FUNCTION_DECLARATION (
    EFI_STATUS,
    Register,
    (
     IN EFI_SMM_RSC_HANDLER_CALLBACK   Callback)
    );

  MOCK_FUNCTION_DECLARATION (
    EFI_STATUS,
    Unregister,
    (IN EFI_SMM_RSC_HANDLER_CALLBACK Callback)
    );
};

MOCK_INTERFACE_DEFINITION (MockSmmReportStatusCodeHandler);
MOCK_FUNCTION_DEFINITION (MockSmmReportStatusCodeHandler, Register, 1, EFIAPI);
MOCK_FUNCTION_DEFINITION (MockSmmReportStatusCodeHandler, Unregister, 1, EFIAPI);

EFI_SMM_RSC_HANDLER_PROTOCOL  SmmRscHandlerProtocolMock = {
  Register,
  Unregister
};

extern "C" {
  EFI_SMM_RSC_HANDLER_PROTOCOL  *gSmmRscHandlerProtocolMock = &SmmRscHandlerProtocolMock;
}

#endif
