#ifndef CSCGEMINT_DATAFORMATS_TMBTYPES_H
#define CSCGEMINT_DATAFORMATS_TMBTYPES_H

template <typename IndexType, typename DigiType>
class MuonDigiCollection;
class CSCDetId;

namespace CSCGEMInt{
class CSCComparator;
typedef MuonDigiCollection<CSCDetId,CSCComparator> CSCComparatorCollection;
}

#endif
