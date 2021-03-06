/**
 *	@file 	inverted_index.hh
 *	@author	Nicolas Wipfler (nwipfler@mail.uni-mannheim.de)
 *	@brief  Implements the inverted index represented by a map of string -> PostingList
 *          The PostingList contains the idf and posting for a term
 *	@bugs 	Currently no bugs known
 *
 *	@section DESCRIPTION doc_to
 */
#pragma once

#include "types.hh"
#include "exception.hh"
#include "trace.hh"
#include "document.hh"
#include "posting_list.hh"
#include "ir_util.hh"

#include <map>
#include <string>

class InvertedIndex {
    friend class IndexManager;

  private:
    InvertedIndex();
    InvertedIndex(const InvertedIndex&) = default;
    InvertedIndex(InvertedIndex&&) = delete;
    InvertedIndex& operator=(const InvertedIndex&) = delete;
    InvertedIndex& operator=(InvertedIndex&&) = delete;
    ~InvertedIndex() = default;

  private:
    /**
     * @brief Insert an empty posting list for aTerm, if this term is not in the inverted index yet
     *
     * @param aTerm the term to insert
     * @param aPostingList the posting list to insert
     * @return true if insertion was successful
     * @return false if insertion failed
     */
    bool insert(const std::string& aTerm, const PostingList& aPostingList);
    /**
     * @brief Find a postingList with aKey and return an iterator
     *
     * @param aKey the term to find in the map
     * @return posting_map_iter_t the postingList for aKey (the term)
     */
    posting_map_iter_t find(const std::string& aKey);
    /**
     * @brief Erase the postingList of aKey
     *
     * @param aKey the term to erase
     */
    void erase(const std::string& aKey);
    /**
     * @brief Erase the postingList for aIterator
     *
     * @param aIterator the iterator to erase with
     */
    void erase(const posting_map_iter_t aIterator);

    /**
     * @brief Get the InvertedIndex Singleton instance.
     *
     * @return InvertedIndex& a reference to the InvertedIndex Singleton instance.
     */
    inline static InvertedIndex& getInstance() {
        static InvertedIndex instance;
        return instance;
    }
    /**
     * @brief Initialize control block and inverted index
     *
     * @param aControlBlock the control block
     * @param aPostingList the posting lists
     */
    void init(const control_block_t& aControlBlock);

    /**
     * @brief Get the term posting map
     * 
     * @return str_postinglist_mt* the term posting map
     */
    inline str_postinglist_mt* getTermPostingMap() { return &_term_posting_map; }

  public:
    /**
     * @brief Get the posting lists
     *
     * @return const str_postinglist_mt& the posting lists
     */
    inline const str_postinglist_mt& getPostingLists() const { return _term_posting_map; }
    /**
     * @brief Get the size of the dictionary
     *
     * @return size_t the distinct number of vocab terms
     */
    inline size_t getDictionarySize() { return _term_posting_map.size(); }

    /**
     * @brief Get the posting list for the given term
     *
     * @param term the term for getting the posting list
     * @return const PostingList& the posting list
     */
    const PostingList& getPostingList(const std::string& term) const;
    /**
     * @brief Get the number of documents in which aTerm appears
     *
     * @param aTerm the term
     * @return size_t the number of documents in which aTerm appears
     */
    size_t getNoDocs(const std::string& aTerm);
    /**
     * @brief Get the doc id list for a given term (so the list of all 
     *        documents where this term appears)
     * 
     * @param terms the term to get the ids for
     * @return sizet_vt the list of ids
     */
    sizet_vt getDocIDList(const string_vt& terms) const;
    
    /**
     * @brief override the <<operator for inverted index
     * 
     * @param strm the output stream
     * @param ii the inverted index instance
     * @return std::ostream& the modified output stream
     */
    friend std::ostream& operator<<(std::ostream& strm, const InvertedIndex& ii);

  private:
    const CB* _cb;

    str_postinglist_mt _term_posting_map; // term, PostingList: [("Frodo", <PostingListObj>), ...]
};
